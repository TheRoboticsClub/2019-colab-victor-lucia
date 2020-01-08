#Creating tasks

import asyncio

async def coro():
	print('hola mundo')
	
task = asyncio.create_task(coro())

await task

asyncio.run(task())
