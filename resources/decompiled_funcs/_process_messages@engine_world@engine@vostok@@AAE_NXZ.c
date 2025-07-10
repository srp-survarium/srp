char __thiscall vostok::engine::engine_world::process_messages(vostok::engine::engine_world *this)
{
  tagMSG message; // [esp+Ch] [ebp-1Ch] BYREF

  if ( !PeekMessageA(&message, 0, 0, 0, 1u) )
    return 1;
  while ( 1 )
  {
    TranslateMessage(&message);
    DispatchMessageA(&message);
    if ( message.message == 18 )
      break;
    if ( !PeekMessageA(&message, 0, 0, 0, 1u) )
      return 1;
  }
  return 0;
}
