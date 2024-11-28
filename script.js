// Simulated data for vehicle count and traffic light status
const vehicleCountElement = document.getElementById("vehicleCount");
const lightStatusElement = document.getElementById("lightStatus");

// Simulate real-time updates
setInterval(() => {
  const vehicleCount = Math.floor(Math.random() * 100); // Random count
  const lightStatus = Math.random() > 0.5 ? "Green" : "Red"; // Random status

  vehicleCountElement.textContent = vehicleCount;
  lightStatusElement.textContent = lightStatus;
}, 2000);

// Chart setup
const ctx = document.getElementById("trafficChart").getContext("2d");
const trafficChart = new Chart(ctx, {
  type: 'line',
  data: {
    labels: ['1 PM', '2 PM', '3 PM', '4 PM', '5 PM'],
    datasets: [{
      label: 'Vehicles Per Hour',
      data: [20, 50, 70, 30, 60],
      borderColor: '#4CAF50',
      borderWidth: 2,
      fill: false,
    }]
  },
  options: {
    responsive: true,
    scales: {
      y: {
        beginAtZero: true
      }
    }
  }
});
