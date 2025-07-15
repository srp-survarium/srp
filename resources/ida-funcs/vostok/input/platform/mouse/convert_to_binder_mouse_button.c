int __usercall vostok::input::platform::mouse::convert_to_binder_mouse_button@<eax>(
        int receiver_button@<eax>,
        vostok::input::platform::mouse *this)
{
  int v2; // eax
  int v3; // eax
  int v5; // eax

  if ( receiver_button > 16 )
  {
    v5 = receiver_button - 32;
    if ( v5 )
    {
      if ( v5 == 32 )
        return 343;
      else
        return 344;
    }
    else
    {
      return 342;
    }
  }
  else if ( receiver_button == 16 )
  {
    return 341;
  }
  else
  {
    v2 = receiver_button - 1;
    if ( v2 )
    {
      v3 = v2 - 1;
      if ( v3 )
      {
        if ( v3 == 2 )
          return 339;
        else
          return 340;
      }
      else
      {
        return 338;
      }
    }
    else
    {
      return 337;
    }
  }
}
