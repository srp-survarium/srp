vostok::input::mouse_button __usercall vostok::input::receiver::mouse::convert_to_binder_mouse_button@<eax>(
        int receiver_button@<eax>,
        vostok::input::receiver::mouse *this)
{
  vostok::input::mouse_button result; // eax

  switch ( byte_565F53[receiver_button] )
  {
    case 0:
      result = mouse_button_left;
      break;
    case 1:
      result = mouse_button_right;
      break;
    case 2:
      result = mouse_button_middle;
      break;
    case 3:
      result = mouse_button_extended0;
      break;
    case 4:
      result = mouse_button_extended1;
      break;
    case 5:
      result = mouse_button_extended2;
      break;
    case 6:
      result = mouse_button_extended3;
      break;
    case 7:
      result = mouse_button_extended4;
      break;
  }
  return result;
}
