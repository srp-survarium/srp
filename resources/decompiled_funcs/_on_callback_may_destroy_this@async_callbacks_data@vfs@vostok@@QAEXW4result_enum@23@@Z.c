void __thiscall vostok::vfs::async_callbacks_data::on_callback_may_destroy_this(
        vostok::vfs::async_callbacks_data *this,
        vostok::vfs::result_enum in_result)
{
  ++this->callbacks_called_count;
  switch ( in_result )
  {
    case result_success:
      this->result = result_success;
      break;
    case result_requery:
      if ( this->result != result_success && this->result )
        this->result = result_requery;
      break;
    case result_undefined:
      this->result = result_undefined;
      break;
  }
  vostok::vfs::async_callbacks_data::try_finish_may_destroy_this(this);
}
