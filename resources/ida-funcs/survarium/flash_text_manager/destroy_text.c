void __userpurge survarium::flash_text_manager::destroy_text(
        survarium::flash_text *text@<esi>,
        survarium::flash_text_manager *this)
{
  Scaleform::RefCountNTSImpl::Release(text->text_impl);
  text->text_impl = 0;
  text->owner = 0;
  text->visible = 0;
  this->need_capture = 1;
}
