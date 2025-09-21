//Delink and export a piece of the program in headless mode.
//@author Jean-Baptiste Boric
//@category Project
//@keybinding
//@menupath
//@toolbar

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.HashMap;
import java.util.Map;

import ghidra.app.plugin.core.analysis.AutoAnalysisManager;
import ghidra.app.services.Analyzer;
import ghidra.app.util.Option;
import ghidra.app.util.OptionException;
import ghidra.app.util.exporter.Exporter;
import ghidra.app.util.exporter.ExporterException;
import ghidra.app.util.headless.HeadlessScript;
import ghidra.program.database.ProgramDB;
import ghidra.program.database.module.TreeManager;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressFactory;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.GhidraClass;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.listing.ProgramModule;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Namespace;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SymbolType;
import ghidra.util.classfinder.ClassSearcher;

import ghidra.program.model.listing.Variable;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.FunctionIterator;

import ghidra.app.util.exporter.CoffRelocatableObjectExporter;

// * Deal with exceptions (not generate those .obj files at all and log stats instead)
// * Parallelize
public class DelinkProgram extends HeadlessScript {
	private static final Pattern TREEPATH_PATTERN = Pattern.compile("^([^:]+):([^/]+(?:/[^/]+)*)$");

	@Override
	public void run() throws Exception {
		String[] args = getScriptArgs();

		// The first argument is the `OUTPUT_DIR`.
		String outputDir = args[0];

		// The second (optional) argument is a filter for classes
		Optional<String> filter = args.length > 1 ? Optional.ofNullable(args[1]) : Optional.empty();

		//
		//
		//

		AutoAnalysisManager aam = AutoAnalysisManager.getAnalysisManager(currentProgram);
		Analyzer analyzer = aam.getAnalyzer("Relocation table synthesizer");

		var exporter = new CoffRelocatableObjectExporter();

		//
		//
		//

		exportClasses(filter, outputDir, aam, analyzer, exporter);
		exportFunctions(filter, outputDir, aam, analyzer, exporter);
	}

	void exportFunctions(
		Optional<String> filter,
		String outputDir,

		AutoAnalysisManager aam,
		Analyzer analyzer,
		Exporter exporter
	) throws Exception {
		FunctionManager fm = currentProgram.getFunctionManager();
		Map<String, AddressSet> map = new HashMap<>();

		var it = fm.getFunctions(true);
		while (it.hasNext()) {
				var func = it.next();

				var namespace = func.getParentNamespace().getName(true);
				if (!(namespace.startsWith("vostok") || namespace.startsWith("survarium"))) {
					continue;
				}

				if (filter.isPresent() && !namespace.startsWith(filter.get())) {
					continue;
				}

				// `this` arguments are already covered by `getClassNamespaces`
				Variable[] vars = func.getAllVariables();
				var has_this = Arrays.stream(vars).anyMatch(v -> "this".equals(v.getName()));
				if (has_this) {
					continue;
				}


				map.computeIfAbsent(namespace, k -> new AddressSet())
					.add(func.getBody());

				var symbol = func.getSymbol();
				println(namespace + " ---> " + symbol.getName());
		}

		for (Map.Entry<String, AddressSet> entry : map.entrySet()) {
				String namespace = entry.getKey();
				AddressSet addressSet = entry.getValue();

				//
				//
				//

				var dirPath = outputDir + "/functions/" + getDirRelativePath(namespace);
				var objFile = new File(dirPath + "/" + getFileNameNamespace(namespace));

				createDirAll(dirPath);
				export(objFile, aam, analyzer, exporter, addressSet);
		}
	}

	void exportClasses(
		Optional<String> filter,
		String outputDir,

		AutoAnalysisManager aam,
		Analyzer analyzer,
		Exporter exporter
	) throws Exception {

		SymbolTable symbolTable = currentProgram.getSymbolTable();


		var it = symbolTable.getClassNamespaces();
		while (it.hasNext()) {
				GhidraClass engineClass = it.next();

				var namespace = engineClass.getParentNamespace().getName(true);
				if (!(namespace.startsWith("vostok") || namespace.startsWith("survarium"))) {
					continue;
				}

				if (filter.isPresent() && !namespace.startsWith(filter.get())) {
					continue;
				}

				var symbol = engineClass.getSymbol();
				println(namespace + " ---> " + symbol.getName());

				var addressSet = new AddressSet();
				addressSet.add(engineClass.getBody());

				//
				//
				//

				var dirPath = outputDir + "/" + getDirRelativePath(namespace);
				var objFile = new File(dirPath + "/" + getFileName(engineClass));

				createDirAll(dirPath);
				export(objFile, aam, analyzer, exporter, addressSet);
		}
	}

	void export(
			File file,
			AutoAnalysisManager aam,
			Analyzer analyzer,
			Exporter exporter,
			AddressSet addressSet
		) throws OptionException, ExporterException, IOException {
		aam.scheduleOneTimeAnalysis(analyzer, addressSet);
		aam.waitForAnalysis(null, getMonitor());

		exporter.setOptions(getOptions(exporter));

		try {
			if (!exporter.export(file, currentProgram, addressSet, monitor)) {
				throw new RuntimeException("Failed to export " + file.getName());
			}
			println("Exported to " + file.getName());

		} catch (Exception e) {
			println("Failed to export " + file.getName());
		}
	}

	AddressSetView findProgramModule(String path) {
		Matcher matcher = TREEPATH_PATTERN.matcher(path);
		if (!matcher.matches()) {
			throw new RuntimeException("Invalid tree path " + path);
		}

		TreeManager treeManager = ((ProgramDB) currentProgram).getTreeManager();
		ProgramModule module = treeManager.getRootModule(matcher.group(1));

		for (String part : matcher.group(2).split("/")) {
			module = (ProgramModule) module.getChildren()[module.getIndex(part)];
		}

		return module.getAddressSet();
	}

	AddressSetView findBlock(String name) {
		Memory memory = currentProgram.getMemory();
		MemoryBlock block = memory.getBlock(name);
		AddressFactory addressFactory = currentProgram.getAddressFactory();
		return addressFactory.getAddressSet(block.getStart(), block.getEnd());
	}

	AddressSetView findRange(String range) {
		String[] parts = range.split("-");
		AddressFactory addressFactory = currentProgram.getAddressFactory();
		Address start = addressFactory.getAddress(parts[0]);
		Address end = addressFactory.getAddress(parts[1]);
		return addressFactory.getAddressSet(start, end);
	}

	AddressSetView findSymbolsInFile(String pathname) throws Exception {
		AddressSet addressSet = new AddressSet();
		List<String> symbols = Files.readAllLines(Paths.get(pathname));
		symbols.forEach(symbol -> addressSet.add(findSymbol(symbol.strip())));
		return addressSet;
	}

	AddressSetView findSymbol(String name) {
		AddressSet addressSet = new AddressSet();
		SymbolTable symbolTable = currentProgram.getSymbolTable();

		for (Symbol symbol : symbolTable.getSymbols(name)) {
			FunctionManager functionManager = currentProgram.getFunctionManager();
			Function function = functionManager.getFunctionAt(symbol.getAddress());

			if (function != null) {
				addressSet.add(function.getBody());
			}
			else {
				Listing listing = currentProgram.getListing();
				CodeUnit codeUnit = listing.getCodeUnitAt(symbol.getAddress());
				AddressFactory addressFactory = currentProgram.getAddressFactory();
				addressSet.add(addressFactory.getAddressSet(codeUnit.getMinAddress(),
					codeUnit.getMaxAddress()));
			}
		}

		return addressSet;
	}

	Exporter findExporter(String name) {
		List<Exporter> exporters = new ArrayList(ClassSearcher.getInstances(Exporter.class));
		return exporters.stream().filter(e -> e.getName().equals(name)).findFirst().get();
	}

	List<Option> getOptions(Exporter exporter) {
		List<Option> options = new ArrayList<>(exporter.getOptions(() -> {
			return currentProgram;
		}));
		return options;
	}


	public static String getDirRelativePath(String namespace) {
			return "./" + namespace
				.replace("::", "/")
				.replace("*", "^")
				.replace("<", "[")
				.replace(">", "]");
	}

	public static String getFileNameNamespace(String namespace) {
			return getFileNameImpl(namespace);
	}

	public static String getFileName(GhidraClass engineClass) {
			var className = engineClass.getSymbol().getName();
			return getFileNameImpl(className);
	}

	public static String getFileNameImpl(String input) {
			return input
				.replace("vostok::", "")
				.replace("stlp_std::", "std-")
				.replace("::", "-")
				.replace("*", "^")
				.replace("<", "[")
				.replace(">", "]")
				+ ".obj";
	}

	public static void createDirAll(String dirPath) throws Exception {
			Path path = Paths.get(dirPath);
			Files.createDirectories(path);
	}

}
