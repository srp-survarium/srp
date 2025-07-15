void __userpurge vostok::animation::mixing::callback_generator_info::callback_generator_info(
        vostok::animation::mixing::callback_generator_info *this@<esi>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation@<eax>,
        const void *animated_object,
        float animation_time,
        unsigned __int16 event_type,
        unsigned __int8 channel_ids,
        unsigned int user_data,
        unsigned __int8 animation_interval_id)
{
  this->animation.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &this->animation.vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>,
    animation);
  this->animated_object = animated_object;
  this->user_data = user_data;
  this->event_type = event_type;
  this->next = 0;
  this->animation_time = animation_time;
  this->channel_ids = channel_ids;
  this->animation_interval_id = animation_interval_id;
}
