int __cdecl Scaleform::Alg::BitCount32(unsigned int value)
{
  if ( value >= 0x8000 )
  {
    if ( value >= (unsigned int)&unk_800000 )
    {
      if ( value >= 0x8000000 )
      {
        if ( value >= 0x20000000 )
        {
          if ( value >= 0x40000000 )
            return 32 - (value < 0x80000000);
          else
            return 30;
        }
        else
        {
          return 29 - (value < 0x10000000);
        }
      }
      else if ( value >= (unsigned int)&vostok::memory::s_CRT_arena[22351416] )
      {
        return 27 - (value < (unsigned int)&vostok::memory::s_CRT_arena[55905848]);
      }
      else
      {
        return 25 - (value < (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
      }
    }
    else if ( value >= 0x80000 )
    {
      if ( value >= 0x200000 )
        return 23 - (value < (unsigned int)Scaleform::GFx::AS2::CreateShadow);
      else
        return 21 - (value < 0x100000);
    }
    else if ( value >= (unsigned int)&loc_20000 )
    {
      return 19 - (value < 0x40000);
    }
    else
    {
      return 17 - (value < (unsigned int)&_sbh_sizeHeaderList);
    }
  }
  else if ( value >= 0x80 )
  {
    if ( value >= 0x800 )
    {
      if ( value >= 0x2000 )
        return 15 - (value < 0x4000);
      else
        return 13 - (value < 0x1000);
    }
    else if ( value >= 0x200 )
    {
      return 11 - (value < 0x400);
    }
    else
    {
      return 9 - (value < 0x100);
    }
  }
  else if ( value >= 8 )
  {
    if ( value >= 0x20 )
      return 7 - (value < 0x40);
    else
      return 5 - (value < 0x10);
  }
  else if ( value >= 2 )
  {
    return 3 - (value < 4);
  }
  else
  {
    return value != 0;
  }
}
