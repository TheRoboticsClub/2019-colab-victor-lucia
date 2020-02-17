#Future

import asyncio

async def main():
	await function_that_returns_a_future_object()
	
	#This is also valid:
	await asyncio.gather(
		function_that_returns_a_future_object(),
		some_python_coroutine()
	)
