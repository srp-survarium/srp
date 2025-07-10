// attributes: thunk
void __thiscall Scaleform::AllocAddr::AddSegment(Scaleform::AllocAddr *this, unsigned int addr, unsigned int size)
{
  Scaleform::AllocAddr::Free(this, addr, size);
}
