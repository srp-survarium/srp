void __usercall survarium::artefact_lifebone_core::regeneration_modifier::regeneration_modifier(
        survarium::artefact_lifebone_core::regeneration_modifier *this@<eax>,
        const survarium::artefact_lifebone_core::regeneration_modifier *__that@<edi>)
{
  vostok::fixed_string<16>::fixed_string<16>(&this->body_part, &__that->body_part);
  this->regen_add = __that->regen_add;
  this->regen_mul = __that->regen_mul;
  this->timeout_add = __that->timeout_add;
  this->timeout_mul = __that->timeout_mul;
  this->threshold_add = __that->threshold_add;
  this->threshold_mul = __that->threshold_mul;
}
