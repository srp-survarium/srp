int __usercall vostok::debug::unhandled_exception_filter@<eax>(
        unsigned int a1@<ebx>,
        int _exception_code,
        _EXCEPTION_POINTERS *const exception_information)
{
  vostok::debug::engine *v4; // eax
  vostok::debug::engine *v5; // [esp+4h] [ebp-201Ch]
  vostok::debug::engine *v6; // [esp+8h] [ebp-2018h]
  survarium::game_camera _Dst[97]; // [esp+10h] [ebp-2010h] BYREF
  LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter; // [esp+2010h] [ebp-10h]
  LPTOP_LEVEL_EXCEPTION_FILTER v9; // [esp+2014h] [ebp-Ch]
  char *_Src; // [esp+2018h] [ebp-8h]
  void (__cdecl *log_callback)(const char *, bool, bool, const char *); // [esp+201Ch] [ebp-4h]

  lpTopLevelExceptionFilter = 0;
  v9 = SetUnhandledExceptionFilter(0);
  if ( !v9 )
    v9 = (LPTOP_LEVEL_EXCEPTION_FILTER)unhandled_exception_handler;
  SetUnhandledExceptionFilter(v9);
  _Src = "<no description>";
  if ( _exception_code > -1073741819 )
  {
    switch ( _exception_code )
    {
      case -1073741795:
        _Src = "ILLEGAL_INSTRUCTION : The thread tries to execute an invalid instruction.";
        break;
      case -1073741787:
        _Src = "NONCONTINUABLE_EXCEPTION : The thread attempts to continue execution after a non-continuable exception occurs.";
        break;
      case -1073741786:
        _Src = "INVALID_DISPOSITION : An exception handler returns an invalid disposition to the exception dispatcher. Pr"
               "ogrammers using a high-level language such as C should never encounter this exception.";
        break;
      case -1073741684:
        _Src = "ARRAY_BOUNDS_EXCEEDED : The thread attempts to access an array element that is out of bounds, \r\n"
               "and the underlying hardware supports bounds checking.";
        break;
      case -1073741683:
        _Src = "FLT_DENORMAL_OPERAND : One of the operands in a floating point operation is denormal. A denormal value is"
               " one that is too small to represent as a standard floating point value.";
        break;
      case -1073741682:
        _Src = "FLT_DIVIDE_BY_ZERO : The thread attempts to divide a floating point value by a floating point divisor of 0 (zero).";
        break;
      case -1073741681:
        _Src = "FLT_INEXACT_RESULT : The result of a floating point operation cannot be represented exactly as a decimal fraction.";
        break;
      case -1073741680:
        _Src = "FLT_INVALID_OPERATION : An unknown floating point exception.";
        break;
      case -1073741679:
        _Src = "FLT_OVERFLOW : The exponent of a floating point operation is greater than the length allowed by the corresponding type.";
        break;
      case -1073741678:
        _Src = "FLT_STACK_CHECK : The stack has overflowed or underflowed, because of a floating point operation.";
        break;
      case -1073741677:
        _Src = "FLT_UNDERFLOW : The exponent of a floating point operation is less than the length allowed by the corresponding type.";
        break;
      case -1073741676:
        _Src = "INT_DIVIDE_BY_ZERO : The thread tries to access a page that is not present, and the system is unable to l"
               "oad the page. For example, this exception might occur if a network connection is lost while running a pro"
               "gram over a network.";
        break;
      case -1073741675:
        _Src = "INT_OVERFLOW : The result of an integer operation causes a carry out of the most significant bit of the result.";
        break;
      case -1073741674:
        _Src = "PRIV_INSTRUCTION : The thread attempts to execute an instruction with an operation that is not allowed in"
               " the current computer mode.";
        break;
      case -1073741571:
        _Src = "STACK_OVERFLOW : The thread uses up its stack.";
        break;
      default:
        break;
    }
  }
  else
  {
    switch ( _exception_code )
    {
      case -1073741819:
        _Src = "ACCESS_VIOLATION : The thread attempts to read from or write to a virtual address for which it does not have access.";
        break;
      case -2147483646:
        _Src = "DATATYPE_MISALIGNMENT : The thread attempts to read or write data that is misaligned on hardware that doe"
               "s not provide alignment. For example, 16-bit values must be aligned on 2-byte boundaries, 32-bit values o"
               "n 4-byte boundaries, and so on.";
        break;
      case -2147483645:
        _Src = "BREAKPOINT : A breakpoint is encountered.";
        break;
      case -2147483644:
        _Src = "SINGLE_STEP : A trace trap or other single instruction mechanism signals that one instruction is executed.";
        break;
    }
  }
  if ( vostok::debug::is_debugger_present() )
    __debugbreak();
  if ( vostok::debug::debug_engine() && (v6 = vostok::debug::debug_engine(), v6->is_testing(v6)) )
  {
    v5 = vostok::debug::debug_engine();
    v5->on_testing_exception(v5, assert_untyped, _Src, exception_information, 0);
    return 1;
  }
  else
  {
    log_callback = vostok::debug::get_log_callback();
    if ( log_callback )
    {
      log_callback("debug", 1, 0, (const char *)&buf);
      log_callback("debug", 1, 0, _Src);
      log_callback("debug", 1, 0, (const char *)&buf);
    }
    if ( show_dialog_for_unhandled_exceptions() )
    {
      strcpy_s((char *)_Dst, 0x2000u, _Src);
      strcat_s((char *)_Dst, 0x2000u, "\r\n\r\n");
      vostok::debug::platform::on_error(
        _Dst,
        a1,
        0,
        (char *const)_Dst,
        (survarium::game_camera *)0x2000,
        0,
        exception_information,
        error_type_unhandled_exception);
    }
    if ( vostok::debug::debug_engine() )
    {
      v4 = vostok::debug::debug_engine();
      if ( ((unsigned __int8 (__thiscall *)(vostok::debug::engine *, vostok::debug::engine *))v4->terminate_on_error)(
             v4,
             v4) )
      {
        vostok::debug::dump_call_stack(a1, (const char *)&buf, 1, 0, 4u, exception_information, 0);
        vostok::debug::terminate((char *)&buf);
      }
    }
    v9(exception_information);
    return 0;
  }
}
