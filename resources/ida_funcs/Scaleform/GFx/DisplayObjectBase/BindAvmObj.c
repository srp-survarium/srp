void __thiscall Scaleform::GFx::DisplayObjectBase::BindAvmObj(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::AvmDisplayObjBase *p)
{
  this->AvmObjOffset = (unsigned int)((char *)p - (char *)this + 3) >> 2;
}
