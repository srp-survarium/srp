void __thiscall Scaleform::GFx::AS2ValueObjectInterface::ObjectRelease(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::Value *val,
        Scaleform::GFx::ASStringNode *pobj)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // ecx
  unsigned int RefCount; // eax

  switch ( val->Type & 0x8F )
  {
    case 6:
      if ( pobj->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pobj);
      break;
    case 7:
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)&pobj[-1].RefCount);
      break;
    case 8:
    case 9:
      if ( (unsigned int)((*((int (__thiscall **)(Scaleform::GFx::ASStringNode *))pobj->pData + 2))(pobj) - 6) > 0x26 )
        v4 = 0;
      else
        v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&pobj[-1].8;
      RefCount = v4->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
      }
      break;
    case 0xA:
      if ( (int)--pobj->pData <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle((Scaleform::GFx::CharacterHandle *)pobj);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pobj);
      }
      break;
    default:
      return;
  }
}
