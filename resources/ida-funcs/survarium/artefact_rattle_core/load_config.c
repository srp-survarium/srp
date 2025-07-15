survarium::artefact_rattle_core::config *__cdecl survarium::artefact_rattle_core::load_config(
        survarium::artefact_rattle_core::config *result,
        vostok::configs::binary_config_value *config)
{
  survarium::artefact_base::config *v2; // esi
  survarium::artefact_rattle_core::config *v3; // eax
  _BYTE v4[20]; // [esp+8h] [ebp-14h] BYREF

  v2 = survarium::artefact_base::load_config((int)v4, config);
  v3 = result;
  qmemcpy(result, v2, sizeof(survarium::artefact_rattle_core::config));
  return v3;
}
