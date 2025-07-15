void __usercall vostok::render::device::device(
        vostok::render::device *this@<eax>,
        vostok::render::device *is_editor@<ecx>)
{
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game = (survarium::game *)this;
  this->m_device = 0;
  this->m_context = 0;
  this->m_is_editor = (char)is_editor;
  this->m_device_removed = 0;
  this->m_avaliable_video_memory = 0;
  vostok::render::device::create(is_editor, (int)this);
}
