void __thiscall Scaleform::GFx::AS2ValueObjectInterface::ObjectAddRef(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::Value *val,
        Scaleform::GFx::Resource *pobj)
{
  switch ( val->Type & 0x8F )
  {
    case 6:
      ++pobj[1].__vftable;
      break;
    case 7:
      Scaleform::RefCountImpl::AddRef(pobj - 1);
      break;
    case 8:
    case 9:
      if ( pobj->GetResourceTypeCode(pobj) - 6 > 0x26 )
        MEMORY[0xC] = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))(((unsigned int)MEMORY[0xC] + 1) & 0x8FFFFFFF);
      else
        pobj[-1].pLib = (Scaleform::GFx::ResourceLibBase *)(((int)&pobj[-1].pLib->__vftable + 1) & 0x8FFFFFFF);
      break;
    case 0xA:
      ++pobj->__vftable;
      break;
    default:
      return;
  }
}
