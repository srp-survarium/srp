void __thiscall survarium::artefact_lifebone_core::modify_regeneration(
        survarium::artefact_lifebone_core *this,
        survarium::body_part_regeneration_info *regeneration_info,
        const survarium::artefact_lifebone_core::regeneration_modifier *regeneration_modifier)
{
  signed int timeout; // eax
  double v4; // st6

  timeout = regeneration_info->timeout;
  regeneration_info->speed = (float)(regeneration_modifier->regen_add + regeneration_info->speed)
                           * regeneration_modifier->regen_mul;
  v4 = (double)(int)regeneration_info->timeout;
  if ( timeout < 0 )
    v4 = v4 + 4294967300.0;
  regeneration_info->timeout = (unsigned __int64)((regeneration_modifier->timeout_add * 1000.0 + v4)
                                                * regeneration_modifier->timeout_mul);
  regeneration_info->threshold = (float)(regeneration_modifier->threshold_add + regeneration_info->threshold)
                               * regeneration_modifier->threshold_mul;
}
