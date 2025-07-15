void __stdcall __noreturn unhandled_exception_handler(_EXCEPTION_POINTERS *const exception_information)
{
  vostok::debug::bugtrap *savedregs; // [esp+0h] [ebp+0h]

  if ( !vostok::debug::bugtrap::initialized() )
    vostok::debug::bugtrap::initialize(savedregs);
  prologue(exception_information);
  epilogue(exception_information);
}
