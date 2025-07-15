Scaleform::Render::FilterEffect *__thiscall Scaleform::Render::CacheEffectChain::GetFilterEffect(
        Scaleform::Render::CacheEffectChain *this)
{
  Scaleform::Render::CacheEffect *i; // esi

  for ( i = this->pEffect; i; i = i->pNext )
  {
    if ( i->GetType(i) == State_ActionControl )
      break;
  }
  return (Scaleform::Render::FilterEffect *)i;
}
