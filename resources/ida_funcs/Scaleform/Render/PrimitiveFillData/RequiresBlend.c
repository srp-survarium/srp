bool __usercall Scaleform::Render::PrimitiveFillData::RequiresBlend@<al>(
        Scaleform::Render::PrimitiveFillData *this@<ecx>,
        int a2@<eax>)
{
  bool result; // al
  int v3; // esi
  _DWORD *i; // edi

  switch ( *(_DWORD *)a2 )
  {
    case 0:
    case 1:
      result = 0;
      break;
    case 2:
      result = *(_BYTE *)(a2 + 7) != 0xFF;
      break;
    case 5:
    case 9:
    case 0xB:
      v3 = 0;
      for ( i = (_DWORD *)(a2 + 12); !*i; ++i )
      {
$LN8_11:
        if ( ++v3 >= 2 )
          return 0;
      }
      switch ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*i + 16))(*i) )
      {
        case 3:
        case 4:
        case 53:
        case 55:
        case 59:
        case 200:
          goto $LN8_11;
        default:
          result = 1;
          break;
      }
      break;
    default:
      result = 1;
      break;
  }
  return result;
}
