vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *__usercall survarium::game_effect_emitter::emit@<eax>(
        survarium::game_effect_emitter *this@<ecx>,
        int a2@<eax>,
        int *a3@<edi>)
{
  int v4; // ecx
  int v5; // eax

  (*(void (__thiscall **)(_DWORD, int *))(**(_DWORD **)(a2 + 264) + 32))(*(_DWORD *)(a2 + 264), a3);
  v4 = *(_DWORD *)(a2 + 272);
  v5 = *a3;
  *(_DWORD *)(v5 + 16) = *(_DWORD *)(a2 + 268);
  *(_DWORD *)(v5 + 20) = v4;
  return (vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)a3;
}
