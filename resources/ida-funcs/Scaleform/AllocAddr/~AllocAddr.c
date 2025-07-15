// attributes: thunk
void __thiscall Scaleform::AllocAddr::~AllocAddr(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddr::destroyAll(this);
}
