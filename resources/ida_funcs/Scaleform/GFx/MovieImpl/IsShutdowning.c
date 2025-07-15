BOOL __thiscall Scaleform::GFx::MovieImpl::IsShutdowning(Scaleform::GFx::MovieImpl *this)
{
  return !this->pRenderRoot.pObject || (this->Flags2 & 4) != 0;
}
