void __userpurge vostok::animation::mixing::callback_generator_info::callback_generator_info(
        vostok::animation::mixing::callback_generator_info *this@<eax>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation@<edi>,
        const void *animated_object,
        float animation_time,
        unsigned __int16 event_type,
        unsigned __int8 channel_ids,
        unsigned int user_data,
        unsigned __int8 animation_interval_id)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &this->animation.vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>,
    animation);
  this->next = 0;
  this->animated_object = animated_object;
  this->user_data = user_data;
  this->event_type = event_type;
  this->channel_ids = channel_ids;
  this->animation_interval_id = animation_interval_id;
  this->animation_time = animation_time;
}
