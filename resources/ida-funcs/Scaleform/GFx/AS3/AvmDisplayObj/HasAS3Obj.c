BOOL __thiscall Scaleform::GFx::AS3::AvmDisplayObj::HasAS3Obj(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  return this->pAS3RawPtr || this->pAS3CollectiblePtr.pObject;
}
