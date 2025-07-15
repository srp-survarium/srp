void __cdecl Scaleform::Render::UserDataEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::UserDataState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::UserDataEffect *v3; // eax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = 74;
  v3 = (Scaleform::Render::UserDataEffect *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              node,
                                              76,
                                              &v4);
  if ( v3 )
    Scaleform::Render::UserDataEffect::UserDataEffect(v3, node, stateArg, next);
}
