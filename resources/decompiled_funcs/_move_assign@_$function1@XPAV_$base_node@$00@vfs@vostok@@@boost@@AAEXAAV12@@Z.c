void __usercall boost::function1<void,vostok::vfs::base_node<1> *>::move_assign(
        boost::function1<void,vostok::vfs::vfs_iterator &> *this@<eax>,
        boost::function1<void,vostok::vfs::vfs_iterator &> *f@<edi>)
{
  boost::detail::function::vtable_base *vtable; // eax
  boost::detail::function::basic_vtable1<void,vostok::vfs::base_node<1> *> *v4; // eax

  if ( f != this )
  {
    vtable = f->vtable;
    if ( f->vtable )
    {
      this->vtable = vtable;
      if ( ((unsigned __int8)vtable & 1) != 0 )
      {
        this->functor = f->functor;
        f->vtable = 0;
      }
      else
      {
        v4 = boost::function1<void,vostok::vfs::vfs_association * &>::get_vtable((boost::function1<void,vostok::vfs::base_node<1> *> *)this);
        v4->base.manager(&f->functor, &this->functor, move_functor_tag);
        f->vtable = 0;
      }
    }
    else
    {
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)this);
    }
  }
}
