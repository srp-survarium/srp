void __cdecl stlp_std::iter_swap<vostok::ai::sound_item const * *,vostok::ai::sound_item const * *>(
        const vostok::ai::movement_target **__i1,
        const vostok::ai::movement_target **__i2)
{
  const vostok::ai::movement_target *v2; // [esp+8h] [ebp-Ch]

  v2 = *__i1;
  *__i1 = *__i2;
  *__i2 = v2;
}
