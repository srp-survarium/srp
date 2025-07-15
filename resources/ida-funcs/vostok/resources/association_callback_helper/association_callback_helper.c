void __thiscall vostok::resources::association_callback_helper::association_callback_helper(
        vostok::resources::association_callback_helper *this)
{
  this->managed.m_object = 0;
  this->unmanaged.m_object = 0;
  this->query = 0;
  this->resource = 0;
  this->reference_count = 0;
  this->associated = 0;
}
