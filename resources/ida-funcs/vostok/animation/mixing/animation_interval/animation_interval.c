void __userpurge vostok::animation::mixing::animation_interval::animation_interval(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *first_view_animation@<eax>,
        vostok::animation::mixing::animation_interval *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *third_view_animation,
        float start_time,
        float length)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &this->m_first_view_animation,
    first_view_animation);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &this->m_third_view_animation,
    third_view_animation);
  this->m_animation_id = -1;
  this->m_start_time = start_time;
  this->m_length = length;
}


void __userpurge vostok::animation::mixing::animation_interval::animation_interval(
        vostok::animation::mixing::animation_interval *this@<eax>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation@<edi>,
        unsigned int animation_id,
        float start_time,
        float length)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &this->m_first_view_animation,
    animation);
  this->m_third_view_animation.m_object = 0;
  this->m_start_time = start_time;
  this->m_animation_id = animation_id;
  this->m_length = length;
}
