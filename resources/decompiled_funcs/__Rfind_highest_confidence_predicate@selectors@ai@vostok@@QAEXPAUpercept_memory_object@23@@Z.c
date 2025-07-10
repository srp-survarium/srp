void __thiscall vostok::ai::selectors::find_highest_confidence_predicate::operator()(
        vostok::ai::selectors::find_highest_confidence_predicate *this,
        vostok::ai::percept_memory_object *memory_object)
{
  vostok::ai::percept_memory_object *object_with_highest_confidence; // [esp+0h] [ebp-10h]
  float recalculated_confidence; // [esp+4h] [ebp-Ch]
  vostok::ai::percept_memory_object *v4; // [esp+8h] [ebp-8h]

  if ( this->object_with_highest_confidence )
  {
    recalculated_confidence = vostok::ai::selectors::get_recalculated_confidence(
                                this->world,
                                this->object_with_highest_confidence);
    if ( vostok::ai::selectors::get_recalculated_confidence(this->world, memory_object) <= (double)recalculated_confidence )
      object_with_highest_confidence = this->object_with_highest_confidence;
    else
      object_with_highest_confidence = memory_object;
    v4 = object_with_highest_confidence;
  }
  else
  {
    v4 = memory_object;
  }
  this->object_with_highest_confidence = v4;
}
