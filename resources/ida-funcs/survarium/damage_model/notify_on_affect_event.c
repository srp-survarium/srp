void __userpurge survarium::damage_model::notify_on_affect_event(
        unsigned int current_time_in_ms@<ecx>,
        survarium::hit_affects_type_enum affect_type@<eax>,
        vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        const char *body_part_name,
        survarium::affect_event_type_enum event_type)
{
  survarium::affect_event_functor pred; // [esp+0h] [ebp-14h] BYREF

  pred.current_time_in_ms = current_time_in_ms;
  pred.affect_type = affect_type;
  pred.body_part_name = body_part_name;
  pred.event_type = event_type;
  vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<survarium::affect_event_functor>(
    this,
    (int)&this[affect_type + 5].m_last,
    &pred);
}
