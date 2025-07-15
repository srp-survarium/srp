int __thiscall Scaleform::GFx::DisplayObjectBase::GetVersion(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::MovieDefImpl *v1; // eax

  v1 = this->GetResourceMovieDef(this);
  return v1->GetVersion(v1);
}
