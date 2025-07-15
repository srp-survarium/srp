int __usercall vostok::render::mesh_type_to_vertex_input_type@<eax>(int type@<eax>)
{
  int v2; // eax
  int v3; // eax

  if ( type > 45 )
  {
    v2 = type - 46;
    if ( v2 )
    {
      v3 = v2 - 1;
      if ( v3 )
      {
        if ( v3 == 54 )
          return 0x2000;
        else
          return 2048;
      }
      else
      {
        return 8;
      }
    }
    else
    {
      return 16;
    }
  }
  else if ( type == 45 )
  {
    return 32;
  }
  else if ( type <= 1 )
  {
    return 2;
  }
  else
  {
    return type == 2 ? 4 : 64;
  }
}
