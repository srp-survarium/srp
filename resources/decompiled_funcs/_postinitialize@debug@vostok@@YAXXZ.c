void __cdecl vostok::debug::postinitialize()
{
  vostok::debug::bugtrap *savedregs; // [esp+0h] [ebp+0h]

  vostok::debug::bugtrap::initialize(savedregs);
}
