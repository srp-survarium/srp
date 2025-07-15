unsigned int __thiscall Scaleform::HeapPT::AllocEngine::SetLimit(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int lim)
{
  unsigned int v3; // eax
  unsigned int result; // eax

  v3 = Scaleform::HeapPT::AllocEngine::calcDynaSize(this);
  result = v3 * ((v3 + lim - 1) / v3);
  this->Limit = result;
  return result;
}
