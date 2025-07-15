void __thiscall Scaleform::GFx::AS3ValueObjectInterface::ObjectRelease(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::Value *val,
        Scaleform::GFx::ASStringNode *pobj)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // ecx
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
    case 0xA:
      v4 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pobj;
      goto LABEL_7;
    case 0xB:
      v4 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((unsigned int)pobj & 0xFFFFFFFD);
LABEL_7:
      RefCount = v4->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
      break;
    default:
      return;
  }
}
