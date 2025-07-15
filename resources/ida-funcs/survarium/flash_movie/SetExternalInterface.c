void __usercall survarium::flash_movie::SetExternalInterface(
        survarium::flash_movie *this@<eax>,
        survarium::flash_external_handler *handler@<edx>)
{
  this->m_movie->SetState(&this->m_movie->Scaleform::GFx::StateBag, State_ExternalInterface, handler->impl);
}
