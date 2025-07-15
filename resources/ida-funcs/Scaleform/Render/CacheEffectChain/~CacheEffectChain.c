void __thiscall Scaleform::Render::CacheEffectChain::~CacheEffectChain(Scaleform::Render::CacheEffectChain *this)
{
  Scaleform::Render::CacheEffect *pEffect; // esi
  Scaleform::Render::CacheEffect *v2; // ecx
  void (__thiscall *v3)(Scaleform::Render::CacheEffect *); // edx

  pEffect = this->pEffect;
  while ( pEffect )
  {
    v2 = pEffect;
    v3 = pEffect->~Scaleform::Render::CacheEffect;
    pEffect = pEffect->pNext;
    ((void (__thiscall *)(Scaleform::Render::CacheEffect *, int))v3)(v2, 1);
  }
}
