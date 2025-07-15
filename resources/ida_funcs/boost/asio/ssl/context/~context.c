void __thiscall boost::asio::ssl::context::~context(boost::asio::ssl::context *this)
{
  void (__thiscall ***v2)(void *, int); // [esp+18h] [ebp-14h]

  if ( this->handle_ )
  {
    if ( this->handle_->default_passwd_callback_userdata )
    {
      (**(void (__thiscall ***)(void *, int))this->handle_->default_passwd_callback_userdata)(
        this->handle_->default_passwd_callback_userdata,
        1);
      this->handle_->default_passwd_callback_userdata = 0;
    }
    if ( X509_STORE_CTX_get_ex_data(this->handle_, 0) )
    {
      v2 = (void (__thiscall ***)(void *, int))X509_STORE_CTX_get_ex_data(this->handle_, 0);
      if ( v2 )
        (**v2)(v2, 1);
      X509_STORE_CTX_set_ex_data(this->handle_, 0, 0);
    }
    SSL_CTX_free(this->handle_);
  }
  if ( this->init_.ref_.pn.pi_ )
    boost::detail::sp_counted_base::release(this->init_.ref_.pn.pi_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->init_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(&this->gap0 + 1));
}
