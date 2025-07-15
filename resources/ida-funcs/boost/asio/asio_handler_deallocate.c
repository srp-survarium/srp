// attributes: thunk
void boost::asio::asio_handler_deallocate(void *pointer, unsigned int size, ...)
{
  operator delete(pointer);
}
