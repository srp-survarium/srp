char __cdecl show_dialog_for_unhandled_exceptions()
{
  char v1; // [esp+0h] [ebp-8h]
  vostok::debug::engine *v2; // [esp+4h] [ebp-4h]

  v1 = 0;
  if ( s_show_dialog_for_unhandled_exceptions )
  {
    if ( vostok::debug::debug_engine() )
    {
      v2 = vostok::debug::debug_engine();
      if ( !v2->terminate_on_error(v2) )
        return 1;
    }
  }
  return v1;
}
