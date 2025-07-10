void __cdecl vostok::debug::finalize()
{
  vostok::debug::bugtrap *savedregs; // [esp+0h] [ebp+0h]

  vostok::debug::bugtrap::finalize(savedregs);
}
