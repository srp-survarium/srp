bool __thiscall Scaleform::GFx::AS2::MouseCtorFunction::IsEmpty(Scaleform::GFx::AS2::MouseCtorFunction *this)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // eax

  pRCC = this->pRCC;
  return pRCC && pRCC[1].RefCount == 0;
}
