void __cdecl Scaleform::Render::ProjectionMatrix3DEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        const Scaleform::Render::ProjectionMatrix3DState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::ProjectionMatrix3DEffect *v3; // eax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = 74;
  v3 = (Scaleform::Render::ProjectionMatrix3DEffect *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        node,
                                                        76,
                                                        &v4);
  if ( v3 )
    Scaleform::Render::ProjectionMatrix3DEffect::ProjectionMatrix3DEffect(v3, node, stateArg, next);
}
