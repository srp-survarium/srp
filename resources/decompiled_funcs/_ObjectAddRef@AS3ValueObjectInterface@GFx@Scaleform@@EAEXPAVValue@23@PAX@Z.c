void __thiscall Scaleform::GFx::AS3ValueObjectInterface::ObjectAddRef(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::Value *val,
        unsigned int pobj)
{
  switch ( val->Type & 0x8F )
  {
    case 6:
      ++*(_DWORD *)(pobj + 12);
      break;
    case 7:
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)(pobj - 12));
      break;
    case 8:
    case 9:
    case 0xA:
      *(_DWORD *)(pobj + 16) = (*(_DWORD *)(pobj + 16) + 1) & 0x8FBFFFFF;
      break;
    case 0xB:
      *(_DWORD *)((pobj & 0xFFFFFFFD) + 0x10) = (*(_DWORD *)((pobj & 0xFFFFFFFD) + 0x10) + 1) & 0x8FBFFFFF;
      break;
    default:
      return;
  }
}
