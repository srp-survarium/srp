void __thiscall vostok::resources::resource_quality::link_child_resource(
        vostok::resources::resource_quality *this,
        vostok::resources::resource_base *child,
        vostok::threading::simple_lock *quality)
{
  vostok::resources::resource_children::link_child_resource(this, (int)quality, (int)this, child, quality);
  if ( quality != (vostok::threading::simple_lock *)-1 )
    this->m_current_quality_level = (unsigned int)quality
                                  + (this->m_current_quality_level < (unsigned int)quality
                                   ? this->m_current_quality_level - (_DWORD)quality
                                   : 0);
}
