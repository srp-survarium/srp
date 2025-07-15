void __cdecl Scaleform::Render::BlendModeEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::BlendState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::BlendModeEffect *v3; // eax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = 74;
  v3 = (Scaleform::Render::BlendModeEffect *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               node,
                                               76,
                                               &v4);
  if ( v3 )
    Scaleform::Render::BlendModeEffect::BlendModeEffect(v3, node, stateArg, next);
}
