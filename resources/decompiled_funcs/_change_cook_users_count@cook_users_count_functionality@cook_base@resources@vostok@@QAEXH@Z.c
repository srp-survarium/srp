void __usercall vostok::resources::cook_base::cook_users_count_functionality::change_cook_users_count(
        vostok::resources::cook_base::cook_users_count_functionality *this@<ecx>,
        int change@<eax>)
{
  if ( change == 1 )
  {
    _InterlockedExchangeAdd(&this->m_count, 1u);
  }
  else if ( change == -1 )
  {
    _InterlockedExchangeAdd(&this->m_count, 0xFFFFFFFF);
  }
}
