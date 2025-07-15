void __thiscall vostok::network::login_client::store_user_password_in_settings(vostok::network::login_client *this)
{
  vostok::strings::copy<128>((char (*)[128])s_net_client_account_password_, this->m_net_client_account_password);
}
