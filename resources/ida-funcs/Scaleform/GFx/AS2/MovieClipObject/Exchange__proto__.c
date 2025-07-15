Scaleform::Ptr<Scaleform::GFx::AS2::Object> *__thiscall Scaleform::GFx::AS2::MovieClipObject::Exchange__proto__(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::Ptr<Scaleform::GFx::AS2::Object> *result,
        Scaleform::GFx::AS2::Object *newproto)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::AS2::Object *v5; // ecx
  unsigned int RefCount; // eax

  pObject = this->pProto.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  result->pObject = (Scaleform::GFx::AS2::Object *)this->pProto;
  if ( newproto )
    newproto->RefCount = (newproto->RefCount + 1) & 0x8FFFFFFF;
  v5 = this->pProto.pObject;
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  this->pProto.pObject = newproto;
  return result;
}
