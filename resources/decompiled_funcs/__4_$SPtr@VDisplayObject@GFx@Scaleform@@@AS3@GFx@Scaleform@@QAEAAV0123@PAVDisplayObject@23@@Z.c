Scaleform::GFx::AS3::SPtr<Scaleform::GFx::DisplayObject> *__thiscall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::DisplayObject>::operator=(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::DisplayObject> *this,
        Scaleform::GFx::DisplayObject *p)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx

  if ( p != this->pObject )
  {
    if ( p )
      ++p->RefCount;
    pObject = this->pObject;
    if ( this->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pObject = (Scaleform::GFx::DisplayObject *)((char *)pObject - 1);
        this->pObject = p;
        return this;
      }
      Scaleform::RefCountNTSImpl::Release(pObject);
    }
    this->pObject = p;
  }
  return this;
}
