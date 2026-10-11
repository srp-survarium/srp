// SPDX-License-Identifier: GPL-3.0-or-later
// Compile our own classes; preserve originals except three narrow insertions.
import java.io.*;
import java.nio.file.*;
import java.util.*;
import com.jpexs.decompiler.flash.SWF;
import com.jpexs.decompiler.flash.abc.ABC;
import com.jpexs.decompiler.flash.abc.avm2.AVM2Code;
import com.jpexs.decompiler.flash.abc.avm2.instructions.AVM2Instruction;
import com.jpexs.decompiler.flash.abc.avm2.parser.script.ActionScript3Parser;
import com.jpexs.decompiler.flash.abc.types.MethodBody;
import com.jpexs.decompiler.flash.tags.Tag;

public class AddMenu {
    // Add a short early-return guard after getlocal0/pushscope. Original
    // relative branches remain byte-identical and must stay within the suffix.
    private static byte[] guard(ABC abc, MethodBody body, int menuName,
                                String helper, boolean returnsBoolean) throws Exception {
        byte[] before = body.getCodeBytes().clone();
        if (before.length < 3 || before[0] != (byte)0xd0 || before[1] != 0x30 ||
            body.exceptions.length != 0) throw new IOException("Unexpected modal method layout");
        AVM2Code original = body.getCode();
        original.markOffsets();
        for (long target : original.getImportantOffsets(body, false))
            if (target < 2) throw new IOException("Modal method branches into prologue");
        AVM2Code prefix = new AVM2Code();
        prefix.code.add(new AVM2Instruction(0, 0x60, new int[]{menuName}));
        prefix.code.add(new AVM2Instruction(0, 0xd0, new int[]{}));
        prefix.code.add(new AVM2Instruction(0, 0x46,
            new int[]{abc.constants.getPublicQnameId(helper, true), 1}));
        prefix.code.add(new AVM2Instruction(0, 0x12, new int[]{returnsBoolean ? 2 : 1}));
        if (returnsBoolean) prefix.code.add(new AVM2Instruction(0, 0x26, new int[]{}));
        prefix.code.add(new AVM2Instruction(0, returnsBoolean ? 0x48 : 0x47, new int[]{}));
        MethodBody temporary = new MethodBody();
        temporary.setCode(prefix);
        byte[] added = temporary.getCodeBytes();
        ByteArrayOutputStream output = new ByteArrayOutputStream();
        output.write(before, 0, 2); output.write(added); output.write(before, 2, before.length-2);
        byte[] after = output.toByteArray();
        body.setCodeBytes(after); body.max_stack = Math.max(body.max_stack, 2);
        body.getCode().checkValidOffsets(body);
        return after;
    }
    public static void main(String[] args) throws Exception {
        SWF swf;
        try (InputStream in = Files.newInputStream(Path.of(args[0]))) {
            swf = new SWF(in, true);
        }
        if (swf.getAbcList().size() != 1) throw new IOException("Expected one ABC");
        ABC abc = swf.getAbcList().get(0).getABC();
        if (abc.findClassByName("SrpMenu") != -1) throw new IOException("Already patched");
        List<byte[]> originalMethods = new ArrayList<>();
        for (MethodBody body : abc.bodies) originalMethods.add(body.getCodeBytes().clone());
        int originalCount = abc.bodies.size();
        for (String filename : new String[]{"SrpJson.as", "SrpResults.as", "SrpMenu.as"}) {
            Path source = Path.of(args[1]).resolveSibling(filename);
            ActionScript3Parser.compile(Files.readString(source), abc,
                swf.getAbcIndex(), filename, abc.instance_info.size(),
                abc.script_info.size(), false, "");
        }
        int menu = abc.findClassByName("SrpMenu");
        if (menu < 0) throw new IOException("Compiler did not add SrpMenu");
        for (int i = 0; i < originalCount; i++) {
            if (!Arrays.equals(originalMethods.get(i), abc.bodies.get(i).getCodeBytes()))
                throw new IOException("Compiler changed original method " + i);
        }
        MethodBody ctor = abc.findBodyInstanceInitializerByClass("LobbyMenu");
        AVM2Code code = ctor.getCode();
        int end = code.code.size() - 1;
        if (code.code.get(end).definition.instructionCode != 0x47 || ctor.exceptions.length != 0)
            throw new IOException("Unexpected LobbyMenu constructor layout");
        // Append SrpMenu.install(this) immediately before the constructor return.
        // Use the library insertion API so branch offsets are adjusted correctly.
        code.insertInstruction(end++, new AVM2Instruction(0, 0x60,
            new int[]{abc.instance_info.get(menu).name_index}), ctor);
        code.insertInstruction(end++, new AVM2Instruction(0, 0xd0, new int[]{}), ctor);
        code.insertInstruction(end, new AVM2Instruction(0, 0x4f,
            new int[]{abc.constants.getPublicQnameId("install", true), 1}), ctor);
        ctor.max_stack = Math.max(ctor.max_stack, 2);
        ctor.setCode(code);
        Map<MethodBody, byte[]> guarded = new IdentityHashMap<>();
        for (String[] pair : new String[][]{{"has_active_window", "isOpen"},
                                           {"close_active_window", "closeOpen"}}) {
            MethodBody body = abc.findBodyByClassAndName("LobbyMenu", pair[0]);
            if (body == null) throw new IOException("Missing modal method " + pair[0]);
            guarded.put(body, guard(abc, body, abc.instance_info.get(menu).name_index,
                                   pair[1], pair[0].equals("has_active_window")));
        }
        ((Tag)abc.parentTag).setModified(true);
        try (OutputStream out = Files.newOutputStream(Path.of(args[2]))) { swf.saveTo(out); }
        // Verify the actual serialized result, not just the in-memory edit.
        try (InputStream in = Files.newInputStream(Path.of(args[2]))) {
            SWF saved = new SWF(in, true);
            ABC actual = saved.getAbcList().get(0).getABC();
            if (actual.findClassByName("SrpMenu") < 0) throw new IOException("Missing saved class");
            for (int i = 0; i < originalCount; i++) {
                if (abc.bodies.get(i) == ctor) {
                    byte[] before = originalMethods.get(i), after = actual.bodies.get(i).getCodeBytes();
                    if (after.length <= before.length || after[after.length - 1] != 0x47
                        || !Arrays.equals(Arrays.copyOf(before, before.length - 1),
                                          Arrays.copyOf(after, before.length - 1)))
                        throw new IOException("Unexpected constructor change after serialization");
                } else if (guarded.containsKey(abc.bodies.get(i))) {
                    if (!Arrays.equals(guarded.get(abc.bodies.get(i)), actual.bodies.get(i).getCodeBytes()))
                        throw new IOException("Saved modal guard changed: " + i);
                } else if (!Arrays.equals(originalMethods.get(i), actual.bodies.get(i).getCodeBytes())) {
                    throw new IOException("Saved method changed: " + i);
                }
            }
        }
        System.out.println("Added SrpMenu; preserved " + (originalCount - 3)
            + " original method bodies; extended constructor and two modal methods");
    }
}
