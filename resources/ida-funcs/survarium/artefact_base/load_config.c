survarium::artefact_base::config *__usercall survarium::artefact_base::load_config@<eax>(
        int a1@<esi>,
        vostok::configs::binary_config_value *result)
{
  const void *pointer; // eax
  const vostok::configs::binary_config_value *v3; // eax
  float v4; // xmm0_4
  const vostok::configs::binary_config_value *v5; // eax
  float v6; // xmm0_4

  pointer = vostok::configs::binary_config_value::operator[](result, "amount")->data.pointer;
  if ( pointer == (const void *)-1 )
    LOWORD(pointer) = -1;
  *(_WORD *)a1 = (_WORD)pointer;
  v3 = vostok::configs::binary_config_value::operator[](result, "cooldown_sec");
  if ( v3->type == 2 )
    v4 = *(float *)&v3->data.pointer;
  else
    v4 = (float)(int)v3->data.pointer;
  *(float *)(a1 + 4) = v4;
  v5 = vostok::configs::binary_config_value::operator[](result, "spawn_sec");
  if ( v5->type == 2 )
    v6 = *(float *)&v5->data.pointer;
  else
    v6 = (float)(int)v5->data.pointer;
  *(float *)(a1 + 8) = v6;
  *(_DWORD *)(a1 + 12) = vostok::configs::binary_config_value::operator[](result, "pickup_hint")->data.pointer;
  *(_DWORD *)(a1 + 16) = vostok::configs::binary_config_value::operator[](result, "activation_hint")->data.pointer;
  return (survarium::artefact_base::config *)a1;
}
