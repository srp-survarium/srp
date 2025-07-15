void __thiscall vostok::ai::dump_memory_facts_predicate::operator()(
        vostok::ai::dump_memory_facts_predicate *this,
        vostok::ai::percept_memory_object *memory_object)
{
  char *v2; // eax
  char *src; // [esp+48h] [ebp-74h]
  unsigned int max_count; // [esp+50h] [ebp-6Ch] BYREF
  vostok::fixed_string<32> value; // [esp+54h] [ebp-68h] BYREF
  vostok::fixed_string<46> new_item_content; // [esp+80h] [ebp-3Ch] BYREF

  src = (char *)this->caption;
  max_count = 46;
  vostok::buffer_string::buffer_string(&new_item_content, new_item_content.m_buffer, &max_count, src);
  v2 = (char *)memory_object->object->get_name((vostok::ai::game_object *)memory_object->object);
  vostok::buffer_string::append(&new_item_content, v2);
  vostok::fixed_string<32>::fixed_string<32>(&value, &new_item_content);
  vostok::buffer_vector<vostok::fixed_string<32>>::push_back(&this->npc_stats->working_memory_state.content, &value);
}
