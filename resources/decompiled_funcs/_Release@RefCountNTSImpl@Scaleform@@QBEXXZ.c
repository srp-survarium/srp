void __thiscall Scaleform::RefCountNTSImpl::Release(Scaleform::RefCountNTSImpl *this)
{
  if ( this->RefCount-- == 1 )
    ((void (__thiscall *)(Scaleform::RefCountNTSImpl *, int))this->~Scaleform::RefCountNTSImpl)(this, 1);
}
